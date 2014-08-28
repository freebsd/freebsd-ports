# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	texinfo
PORTVERSION=	5.2.20140808
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/texinfo/${PORTVERSION:E}/ \
		GNU
DISTNAME=	${PORTNAME}-${PORTVERSION:R}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} htmlxref.cnf texinfo.tex texi2dvi
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Typeset documentation system with multiple format output

BUILD_DEPENDS+=	help2man:${PORTSDIR}/misc/help2man

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install install-tex
PKGDEINSTALL=	${PKGINSTALL}
USES+=		charsetfix gmake:lite perl5 tar:xz

MAKE_ARGS=	TEXMF=${LOCALBASE}/${TEXMF} PERL=${LOCALBASE}/bin/perl
INFO=		texinfo info-stnd info

TEXMF=		share/texmf
PLIST_SUB=	TEXMF=${TEXMF}

post-patch:
	${CHMOD} 755 ${WRKSRC}/build-aux/install-sh
	${CP} ${DISTDIR}/texinfo.tex ${WRKSRC}/doc/
	${CP} ${DISTDIR}/texi2dvi ${WRKSRC}/util/

post-install:
	${INSTALL_DATA} ${DISTDIR}/htmlxref.cnf ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
