# New ports collection makefile for:	get_flash_videos
# Date created:		Sun Jul 22 20:49:07 UTC 2012
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	get_flash_videos
DISTVERSION=	1.24.${DISTFILE_DATE}
CATEGORIES=	www perl5
MASTER_SITES=	https://github.com/downloads/njtaylor/get-flash-videos/
DISTNAME=	${PORTNAME}-1.24-git-${DISTFILE_DATE}
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Download videos from various Flash-based video hosting sites

LICENSE=	AL2

RUN_DEPENDS=	\
		p5-Crypt-Blowfish_PP>=0:${PORTSDIR}/security/p5-Crypt-Blowfish_PP \
		p5-Crypt-Rijndael>=0:${PORTSDIR}/security/p5-Crypt-Rijndael \
		p5-Data-AMF>=0:${PORTSDIR}/converters/p5-Data-AMF \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-IO-Compress>=0:${PORTSDIR}/archivers/p5-IO-Compress \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize>=0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		rtmpdump>=2.4.0:${PORTSDIR}/multimedia/rtmpdump

FETCH_ARGS=	-Fpr	# work around 302 redirect at github
USE_PERL5=	5.8.0+
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
		${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
