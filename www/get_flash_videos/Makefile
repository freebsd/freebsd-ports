# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	get_flash_videos
DISTVERSION=	1.24.${DISTFILE_DATE}
CATEGORIES=	www perl5
MASTER_SITES=	https://github.com/downloads/njtaylor/get-flash-videos/
DISTNAME=	${PORTNAME}-1.24-git-${DISTFILE_DATE}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download videos from various Flash-based video hosting sites

LICENSE=	APACHE20

RUN_DEPENDS=	\
		p5-Crypt-Blowfish_PP>=0:security/p5-Crypt-Blowfish_PP \
		p5-Crypt-Rijndael>=0:security/p5-Crypt-Rijndael \
		p5-Data-AMF>=0:converters/p5-Data-AMF \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-IO-Compress>=0:archivers/p5-IO-Compress \
		p5-URI>=0:net/p5-URI \
		p5-WWW-Mechanize>=0:www/p5-WWW-Mechanize \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		rtmpdump>=2.4.0:multimedia/rtmpdump

USES=		perl5
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DISTFILE_DATE=	20120610

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/env perl|${PERL}|' \
		${WRKSRC}/${DISTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
