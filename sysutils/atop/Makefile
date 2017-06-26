# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	atop
PORTVERSION=	2.0.2.b3
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	ASCII Monitor for system resources and process activity

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	samm-git
GH_PROJECT=	atop-freebsd
GH_TAGNAME=	${PORTNAME}-${PORTVERSION:C|b|fbsd.beta|}

USES=		ncurses
MAKEFILE=	BSDmakefile
LOGDIR?=	/var/log/atop
PLIST_SUB+=	LOGDIR="${LOGDIR}"
SUB_LIST=	LOGDIR="${LOGDIR}"

USE_RC_SUBR=	atop
SUB_FILES=	pkg-message

PORTDOCS=	AUTHOR \
		ChangeLog \
		ChangeLog.FreeBSD \
		README \
		README.FreeBSD

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/atop ${STAGEDIR}${PREFIX}/bin
		${LN} -sf atop ${STAGEDIR}${PREFIX}/bin/atopsar
.for manpage in atop.1 atopsar.1
		${INSTALL_MAN} ${WRKSRC}/man/${manpage} ${STAGEDIR}${MAN1PREFIX}/man/man1/
.endfor
		${INSTALL_MAN} ${WRKSRC}/man/atoprc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5/
		@${MKDIR} ${STAGEDIR}${LOGDIR}
		@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
		${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
