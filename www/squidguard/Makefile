# New ports collection makefile for:    squidGuard
# Date created:        5 June 2000
# Whom:                dl@tyfon.net
#
# $FreeBSD$
#

PORTNAME=	squidGuard
PORTVERSION=	1.1.4
CATEGORIES=	www
MASTER_SITES=	http://ftp.ost.eltele.no/pub/www/proxy/squidGuard/ \
		ftp://ftp.ost.eltele.no/pub/www/proxy/squidGuard/

MAINTAINER=	ports@tyfon.net

BUILD_DEPENDS=	${LOCALBASE}/lib/libdb2.a:${PORTSDIR}/databases/db
RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid23

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-db-inc=${PREFIX}/include/db2 \
		--with-db-lib=${PREFIX}/lib \
		--with-sg-config=${PREFIX}/etc/squid/squidguard.conf \
		--with-sg-dbhome=${DATADIR} \
		--with-sg-logdir=${LOGDIR}

###	To change any of the below paths add it to your make arg
.if !defined(DATADIR)
DATADIR=	/var/db/${PORTNAME}
.endif
.if !defined(LOGDIR)
LOGDIR=		/var/log
.endif

PLIST_SUB=	DATADIR=${DATADIR}

###	To optimize squidGuard add OPTIMIZE=YES to your make arg

.if defined(OPTIMIZE) && ${OPTIMIZE} == YES
CC=		gcc
CFLAGS=		-pipe -O6 -Wall -fomit-frame-pointer
.endif

post-install:

###	Install documentation

.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing ${PORTNAME} documentation"
	-@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
.for i in ${WRKSRC}/doc/*.txt ${WRKSRC}/doc/*.html ${WRKSRC}/doc/*.gif ${WRKSRC}/doc/README
	@${INSTALL_DATA} ${WRKSRC}$i ${PREFIX}/share/doc/${PORTNAME}
.endfor
	@${ECHO_MSG} "       -> Documentation installed in: ${PREFIX}/share/doc/${PORTNAME}"
.endif

### 	Install blacklist databases

.if !exists(${DATADIR})
	@${ECHO_MSG} "===>   Installing blacklist databases"
	@${MKDIR} ${DATADIR}
	@cd ${DATADIR} ; \
	${TAR} fpxz ${WRKSRC}/samples/dest/blacklists.tar.gz ; \
	for f in blacklists/* ; do \
		${MV} $$f ${DATADIR} ; \
	done
	@if [ -d ${PREFIX}/share/doc/${PORTNAME} ] ; then \
		${MV} -f ${DATADIR}/README \
		${PREFIX}/share/doc/${PORTNAME}/README.blacklists ; \
	else \
		${RM} -f ${DATADIR}/README ; \
	fi
	@for d in ${DATADIR}/ads ${DATADIR}/agressive ${DATADIR}/drugs \
			${DATADIR}/hacking ${DATADIR}/porn ; do \
		cd $$d ; \
		${RM} -f newdomains.* newurls.* ; \
		${CHOWN} root.nobody * ; \
		${CHMOD} 640 * ; \
		cd ${DATADIR} ; \
	done
	@${RM} -rf ${DATADIR}/blacklists*
	@${CHOWN} root.nobody ${DATADIR}/* ${DATADIR}
	@${CHMOD} 750 ${DATADIR}/* ${DATADIR}
	@${ECHO_MSG} "       -> Blacklists installed in: ${DATADIR}"
.else
	@${ECHO_MSG} "===>   Found existing datadirectory - skipping blacklist installation"
.endif

###	Install sample configuration file

	@if [ ! -f ${PREFIX}/etc/squid/squidguard.conf ] ; then \
		${ECHO_MSG} "===>   Installing sample configuration file" ; \
		${SED} -e 's!%%DATADIR%%!${DATADIR}!' -e 's!%%LOGDIR%%!${LOGDIR}!' \
			${WRKSRC}/samples/sample.conf > \
			${PREFIX}/etc/squid/squidguard.conf.sample ; \
		${CHOWN} root.nobody ${PREFIX}/etc/squid/squidguard.conf.sample ; \
		${CHMOD} 640 ${PREFIX}/etc/squid/squidguard.conf.sample ; \
		${ECHO_MSG} "       -> Sample configuration file installed in: ${PREFIX}/etc/squid" ; \
	else \
		${ECHO_MSG} "===>   Existing configuration file found - sample not installed" ; \
	fi

.if !exists(${LOGDIR})
	@${MKDIR} ${LOGDIR}
.endif

###	View short howto message

	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} "= In order to activate ${PORTNAME} you have to edit squid.conf"
	@${ECHO_MSG} "= To the contain \"redirect_program	${PREFIX}/bin/${PORTNAME}\""
	@${ECHO_MSG} "= and create a configuration file for ${PORTNAME}."
	@${ECHO_MSG} "="
	@${ECHO_MSG} "= To activate the changes do a ${PREFIX}/sbin/squid -k reconfigure"
	@${ECHO_MSG} "==================================================================="
	@${ECHO_MSG} " "

.include <bsd.port.mk>
