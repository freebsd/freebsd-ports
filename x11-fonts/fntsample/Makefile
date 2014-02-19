# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fntsample
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	x11-fonts
MASTER_SITES=	SF/fntsample/fntsample/${PORTVERSION} \
		http://unicode.org/Public/6.0.0/ucd/:unidata
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		Blocks.txt:unidata
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Show Unicode coverage of a font

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/bin/gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	${LOCALBASE}/bin/pdfoutline:${PORTSDIR}/textproc/pdfoutline

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

CONFIGURE_ARGS=	--disable-silent-rules \
		--with-unicode-blocks=${WRKSRC}/Blocks.txt
GNU_CONFIGURE=	yes
USE_GNOME=	pango
USE_PERL5=	run
USES=		gettext perl5 pkgconfig

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz \
		%%NLS%%share/locale/uk/LC_MESSAGES/${PORTNAME}.mo

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Blocks.txt ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -e '/^bin_SCRIPTS/d' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/po/uk.gmo ${STAGEDIR}${PREFIX}/share/locale/uk/LC_MESSAGES/${PORTNAME}.mo

.include <bsd.port.mk>
