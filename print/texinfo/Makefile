# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	5.2.20131109
CATEGORIES=	print
MASTER_SITES=	GNU \
		ftp://ftp.stack.nl/pub/users/johans/texinfo/${PORTVERSION:E}/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} htmlxref.cnf texinfo.tex texi2dvi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A typeset documentation system with multiple format output

BUILD_DEPENDS+=	help2man:${PORTSDIR}/misc/help2man

FETCH_ARGS=	-Ap
GNU_CONFIGURE=	yes
USE_XZ=		yes
INSTALL_TARGET=	install install-tex
PKGDEINSTALL=	${PKGINSTALL}
USES+=		charsetfix gmake perl5

MAKE_ARGS=	TEXMF=${PREFIX}/${TEXMF} PERL=${LOCALBASE}/bin/perl
INFO=		${PORTNAME} info-stnd info

TEXMF=		share/texmf
PLIST_SUB=	TEXMF=${TEXMF}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/lib
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${CHMOD} 755 ${WRKSRC}/build-aux/install-sh
	${CP} ${DISTDIR}/texinfo.tex ${WRKSRC}/doc/
	${CP} ${DISTDIR}/texi2dvi ${WRKSRC}/util/

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${INSTALL_DATA} ${DISTDIR}/htmlxref.cnf ${STAGEDIR}/${DATADIR}/

.include <bsd.port.mk>
