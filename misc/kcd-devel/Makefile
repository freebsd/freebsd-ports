# New ports collection makefile for:	kcd
# Date created:				5 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	kcd
PORTVERSION=	7.0.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Change directory in full-screen visual mode

USE_GETTEXT=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"

MAN1=		kcd.1

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.csh.init ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/kcd.sh.init ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
