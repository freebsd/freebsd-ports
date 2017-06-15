# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	kcd
PORTVERSION=	7.15.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change directory in full-screen visual mode

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gettext ncurses perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kcd-inst ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kcdscr ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kcdmain ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kcd.1 ${STAGEDIR}${MANPREFIX}/man/man1
.for i in en_GB en_GB.UTF-8 en_US.UTF-8
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo \
		${STAGEDIR}${PREFIX}/share/locale/${i}/LC_MESSAGES/kcd.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.csh.init ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.sh.init ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
