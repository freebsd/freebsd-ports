# New ports collection makefile for:	chemtool
# Date created:			Mar 31, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.6.6
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Draw organic molecules easily and store them

LIB_DEPENDS=	EMF.1:${PORTSDIR}/graphics/libemf
RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

USE_GNOME=	gtk20
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libEMF
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS+="${CFLAGS}" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-emf=yes --with-localedir=${PREFIX}

MAN1=	chemtool.1 cht.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chemtool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src-cht/cht ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/chemtool.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cht.1 ${MANPREFIX}/man/man1
.for lang in cs de fr pl pt_BR ru
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/locales/${lang}/chemtool.mo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
