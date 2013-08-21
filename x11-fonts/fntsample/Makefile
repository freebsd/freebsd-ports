# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	fntsample
PORTVERSION=	3.2
PORTREVISION?=	1
CATEGORIES?=	x11-fonts
MASTER_SITES=	SF/fntsample/fntsample/${PORTVERSION} http://unicode.org/Public/6.0.0/ucd/:unidata
DISTNAME=	fntsample-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Blocks.txt:unidata
EXTRACT_ONLY=	${DISTFILES:M*gz}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT?=	Show Unicode coverage of a font

LICENSE=	GPLv3

USE_PERL5=	run
USES=		perl5

MAN1=		${PORTNAME}.1

.if defined(PDFOUTLINE)
RUN_DEPENDS+=	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
		p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2

NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}
.else
BUILD_DEPENDS+=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS+=	pdfoutline:${PORTSDIR}/textproc/pdfoutline

CONFIGURE_ARGS+=--disable-silent-rules \
		--with-unicode-blocks=${WRKSRC}/Blocks.txt
GNU_CONFIGURE=	yes
USE_GNOME=	pango
USES+=		gettext

PLIST_FILES=	bin/${PORTNAME} share/locale/uk/LC_MESSAGES/${PORTNAME}.mo
.endif

post-extract:
.if !defined(PDFOUTLINE)
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Blocks.txt ${WRKSRC}
.endif

post-patch:
.if defined(PDFOUTLINE)
	@${SED} -e 's|##PACKAGE##|fntsample|g ; \
		 s|##LOCALEDIR##|${PREFIX}/share/locale|g' \
			${WRKSRC}/${PORTNAME}.pl > ${WRKSRC}/${PORTNAME}
	@${SED} -e 's|@DATE@|2008-10-22|g' \
		${WRKSRC}/${PORTNAME}.1.in > ${WRKSRC}/${PORTNAME}.1
.else
	@${REINPLACE_CMD} -e \
		's|^bin_SCRIPTS|#bin_SCRIPTS|g' ${WRKSRC}/Makefile.in
.endif

do-install:
.if defined(PDFOUTLINE)
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
.else
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/locale/uk/LC_MESSAGES
	${INSTALL_DATA} ${WRKSRC}/po/uk.gmo \
		${PREFIX}/share/locale/uk/LC_MESSAGES/${PORTNAME}.mo
.endif

.include <bsd.port.mk>
