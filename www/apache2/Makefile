# New ports collection makefile for:	apache2
# Date created:				7 April 2001
# Whom:					Hye-Shik Chang <perky@python.or.kr>
#
# $FreeBSD$
#

PORTNAME=	apache
PORTVERSION=	2.0.16
PORTREVISION=	1
CATEGORIES=	www ipv6
MASTER_SITES=	http://httpd.apache.org/dist/httpd/ \
		http://www.cybernic.com/mirror/dist/httpd/ \
		http://mirrors.partnersforever.net/apache/dist/httpd/ \
		http://www.technotopia.com/vroom/apache/dist/httpd/ \
		http://www.tux.org/pub/net/apache/dist/httpd/ \
		ftp://ftp.raver.net/pub/ftp.apache.org/httpd/ \
		ftp://ftp.epix.net/pub/apache/dist/httpd/ \
		ftp://ftp.connectnet.com/pub/www/apache/httpd/ \
		ftp://ftp.digex.net/pub/packages/network/apache/httpd/ \
		ftp://ftp.cuckoo.com/pub/mirrors/apache/httpd/
DISTNAME=	httpd-${PORTVERSION:S/./_/g}-beta

MAINTAINER?=	perky@python.or.kr

WRKSRC=		${WRKDIR}/httpd-${PORTVERSION:S/./_/g}
FIND?=		find
XARGS?=		xargs

# apache2 doesn't process '--enable-share=max' option yet.
# and some modules are very unstable at DSO mode.
SHARED_MODS?=	unique_id mime_magic rewrite speling auth_db \
		auth_anon digest headers cern_meta expires include \
		cgid status info usertrack dav dav_fs imap proxy \
		auth_digest file_cache echo optional_fn_import \
		optional_fn_export
STATIC_MODS?=	so env setenvif dir autoindex access auth negotiation \
		userdir alias asis cgi mime log_config vhost_alias actions

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--prefix=${PREFIX} \
		--enable-layout=FreeBSD \
		--with-perl=${PERL} \
		--with-suexec-docroot=${PREFIX}/www/data \
		--enable-shared \
		--disable-threads \
		--with-mpm=prefork  # Apache's thread doesn't work well in FreeBSD

OPTIM+=		-DHARD_SERVER_LIMIT=512 \
		-DDEFAULT_PATH=\\"/bin:/usr/bin:${PREFIX}/bin\\"

CONFIGURE_ENV=	OPTIM='${OPTIM}'

MAN1=		dbmmanage.1 htdigest.1 htpasswd.1
MAN8=		ab.8 apachectl.8 apxs.8 httpd.8 logresolve.8 rotatelogs.8 suexec.8

.for mod in ${SHARED_MODS}
CONFIGURE_ARGS+= --enable-${mod}=shared
.endfor
.for mod in ${STATIC_MODS}
CONFIGURE_ARGS+= --enable-${mod}=yes
.endfor

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig"|${XARGS} ${RM} -f

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/apache.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/apache.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/apache.sh ${PREFIX}/etc/rc.d/apache.sh; \
	fi

.include <bsd.port.mk>
