# New ports collection makefile for:    apache HTTPD
# Version required:     1.3
# Date created:         Fri Aug 25 16:42:36 CDT 1995
# Whom:                 ache@nagual.pp.ru
#
# $Id: Makefile,v 1.44 1998/02/20 11:08:40 ache Exp $
#

DISTNAME=       apache_1.3b5
PKGNAME=        apache-1.3b5
CATEGORIES=	www
MASTER_SITES=   ftp://www.apache.org/apache/dist/

#PATCH_SITES=    ftp://www.apache.org/apache/dist/patches/apply_to_1.3b5/
#PATCHFILES=
#PATCH_DIST_ARGS= -d ${WRKSRC}/src/main -E -p0

MAINTAINER=     ache@freebsd.org

NO_LATEST_LINK=	yes

# Set it for local-supplied patch, f.e.
# VERS_ID = mods-1.0/me

post-patch:
	@cd ${WRKSRC}/conf && \
	for I in access.conf-dist srm.conf-dist; do \
	    sed -e "s#@@ServerRoot@@#${PREFIX}/www#g" < $${I} > $${I}.new; \
	    mv $${I}.new $${I}; \
	done
	@cd ${WRKSRC}/conf && \
	sed -e "s#@@ServerRoot@@#${PREFIX}/etc/apache#g" < \
		httpd.conf-dist > httpd.conf-dist.new && \
	mv httpd.conf-dist.new httpd.conf-dist
	@${RM} -rf ${WRKSRC}/icons/CVS
.if defined(VERS_ID)
	@cd ${WRKSRC}/src && \
	mv Configuration Configuration.old && \
	sed 's;^#*OPTIM=.*;OPTIM= -DSERVER_SUBVERSION=\\"${VERS_ID}\\";' \
	< Configuration.old > Configuration
.endif

CONF_DIR=   ${PREFIX}/etc/apache
MAN1=   apachectl.1 htpasswd.1
MAN8=   httpd.8

do-install:
	install -d -m 755 -o bin -g bin ${CONF_DIR} ${PREFIX}/www/data \
		${PREFIX}/www/icons ${PREFIX}/www/cgi-bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/httpd ${PREFIX}/sbin
	cd ${WRKSRC}/src/support && \
		${INSTALL_PROGRAM} htdigest htpasswd logresolve rotatelogs \
		${PREFIX}/sbin
	cd ${WRKSRC}/src/support && \
		${INSTALL_SCRIPT} apachectl dbmmanage log_server_status \
		${PREFIX}/sbin
	${INSTALL_DATA} -o nobody ${WRKSRC}/icons/* ${PREFIX}/www/icons
	${INSTALL_MAN} ${WRKSRC}/src/support/httpd.8 \
		${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/support/htpasswd.1 \
		       ${WRKSRC}/src/support/apachectl.1 \
		${PREFIX}/man/man1
	cd ${WRKSRC} && \
	for file in httpd.conf srm.conf access.conf ; do \
	    if [ ! -f ${CONF_DIR}/$$file ] ; then \
		${INSTALL_DATA} conf/$$file-dist ${CONF_DIR}/$$file ; \
	    fi ; \
	    ${INSTALL_DATA} conf/$$file-dist ${CONF_DIR} ; \
	done
	cd ${WRKSRC} && \
	for file in mime.types magic ; do \
	    if [ ! -f ${CONF_DIR}/$$file ] ; then \
		${INSTALL_DATA} conf/$$file ${CONF_DIR} ; \
	    fi ; \
	    ${INSTALL_DATA} conf/$$file ${CONF_DIR}/$${file}-dist ; \
	done

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		echo "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		echo "#!/bin/sh" > ${PREFIX}/etc/rc.d/apache.sh; \
		echo "[ -x /usr/local/sbin/httpd ] && /usr/local/sbin/httpd && echo -n ' httpd'" >> ${PREFIX}/etc/rc.d/apache.sh; \
		chmod 751 ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
