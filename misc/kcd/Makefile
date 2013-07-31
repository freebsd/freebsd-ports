# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	kcd
PORTVERSION=	7.15.0
PORTEPOCH=	1
CATEGORIES=	misc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change directory in full-screen visual mode

LICENSE=	GPLv2

USES=		gettext perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

MAN1=		kcd.1

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/kcd-inst ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/kcdscr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kcdmain ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/kcd.1 ${MANPREFIX}/man/man1
.for i in en_GB en_GB.UTF-8 en_US.UTF-8
	@${MKDIR} ${PREFIX}/share/locale/${i}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/${i}.gmo \
		${PREFIX}/share/locale/${i}/LC_MESSAGES/kcd.mo
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.csh.init ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.sh.init ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
