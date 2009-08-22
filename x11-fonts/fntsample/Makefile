# New ports collection makefile for:	fntsample
# Date created:		22 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	fntsample
PORTVERSION=	3.0
PORTREVISION?=	0
CATEGORIES?=	x11-fonts
MASTER_SITES=	SF/fntsample/fntsample/${PORTVERSION} http://unicode.org/Public/5.1.0/ucd/:unidata
DISTNAME=	fntsample-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} Blocks.txt:unidata
EXTRACT_ONLY=	${DISTFILES:M*gz}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Show Unicode coverage of a font

USE_PERL5_RUN=	yes

.if defined(PDFOUTLINE)
RUN_DEPENDS=	p5-Locale-libintl>=0:${PORTSDIR}/devel/p5-Locale-libintl \
		p5-PDF-API2>=0:${PORTSDIR}/textproc/p5-PDF-API2

NO_BUILD=	yes

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}
.else
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk
RUN_DEPENDS=	pdfoutline:${PORTSDIR}/textproc/pdfoutline

USE_GNOME=	pango
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-unicode-blocks=${WRKSRC}/Blocks.txt

MAN1=		${PORTNAME}.1
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
