# New ports collection makefile for:	MToolsFM
# Date created:				12 Jan 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	mtoolsfm
PORTVERSION=	1.9.3
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.core-coutainville.org/MToolsFM/archive/SOURCES/
DISTNAME=	MToolsFM-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A graphical frontend to mtools

RUN_DEPENDS=	mtools:${PORTSDIR}/emulators/mtools

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-conffile="${PREFIX}/etc/mtoolsfm.conf"

MAN1=		mtoolsfm.1

post-patch:
	@${REINPLACE_CMD} -e 's|MToolsFM|mtoolsfm|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/MToolsFM.1
	@${FIND} ${WRKSRC} -name 'Makefile.in' | ${XARGS} ${REINPLACE_CMD} -e \
		's|MToolsFM|mtoolsfm|g'
.for file in src/mtoolsfm.h po/de.po po/fr.po
	@${MV} -f ${WRKSRC}/${file} ${WRKSRC}/${file}.preedit
	@${CAT} ${WRKSRC}/${file}.preedit | \
		${TR} '\264' '\047' > ${WRKSRC}/${file}
.endfor

pre-build:
	@${LN} -sf ${WRKSRC}/MToolsFM.1 ${WRKSRC}/mtoolsfm.1

.include <bsd.port.mk>
