# New ports collection makefile for:	privoxy
# Date created:				21 November 2002
# Whom:					John von Essen
#
# $FreeBSD$
#

PORTNAME=	privoxy
PORTVERSION=	3.0.3
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ijbswa
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	john@essenz.com
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:253

USE_RC_SUBR=	privoxy.sh
SUB_FILES=	pkg-message

MAKEFILE=	GNUmakefile

MAN1=		privoxy.1

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /var/log/privoxy,' \
		-e 's,^\(actionsfile standard\),#\1,' \
		-e 's,^\(actionsfile user\),#\1,' \
	${WRKSRC}/config

pre-configure:
	@cd ${WRKSRC}; ${AUTOHEADER}

pre-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@${MKDIR} ${PREFIX}/etc/privoxy/templates
	@${INSTALL_PROGRAM} ${WRKSRC}/privoxy ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/templates/[a-z]* ${PREFIX}/etc/privoxy/templates
.for file in config default.action default.filter trust
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/etc/privoxy
.endfor
	@${INSTALL_MAN}  ${WRKSRC}/privoxy.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/privoxy-manual
	@if [ -d ${WRKSRC}/doc/webserver/user-manual ]; then \
		${INSTALL_DATA} ${WRKSRC}/doc/webserver/user-manual/[a-z]* ${PREFIX}/share/doc/privoxy-manual; \
	fi
.endif

post-install:
	${MKDIR} /var/log/privoxy
	${CHOWN} privoxy:privoxy /var/log/privoxy
	${CHMOD} 0750 /var/log/privoxy
	${MKDIR} /var/run/privoxy
	${CHOWN} privoxy:privoxy /var/run/privoxy
	${CHMOD} 0750 /var/run/privoxy
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
