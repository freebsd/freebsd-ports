# New ports collection makefile for:	privoxy
# Date created:				21 November 2002
# Whom:					John von Essen
#
# $FreeBSD$
#

PORTNAME=	privoxy
PORTVERSION=	3.0.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ijbswa
DISTNAME=	privoxy-${PORTVERSION}-stable-src

MAINTAINER=	john@essenz.com
COMMENT=	Privoxy is a web proxy with advanced filtering capabilities

WRKSRC=		${WRKDIR}/privoxy-${PORTVERSION}-stable

PKGMESSAGE=	${WRKDIR}/pkg-message

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=PREFIX=${PREFIX} RC_SUBR=${RC_SUBR} # stolen from net/nylon
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
USE_REINPLACE=	yes

MAKEFILE=	GNUmakefile

MAN1=		privoxy.1

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/privoxy.sh.in > ${WRKSRC}/privoxy.sh

post-patch:
	${REINPLACE_CMD} \
		-e 's,^\(confdir\) \.,\1 ${PREFIX}/etc/privoxy,' \
		-e 's,^\(logdir\) \.,\1 /tmp,' \
		-e 's,^\(actionsfile standard\),#\1,' \
		-e 's,^\(actionsfile user\),#\1,' \
	${WRKSRC}/config

pre-configure:
	@cd ${WRKSRC}; ${AUTOHEADER}

pre-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		${PKGDIR}/pkg-message.in > ${PKGMESSAGE}

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
	${INSTALL_SCRIPT} ${WRKSRC}/privoxy.sh ${PREFIX}/etc/rc.d/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
