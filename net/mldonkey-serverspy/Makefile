# New ports collection makefile for:	MLDonkey Server Spy
# Date created:				Fri Feb 21 14:47:25 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	1.2
CATEGORIES=	net
MASTER_SITES=	http://www.moviegalaxy.com.ar/mlservspy/
PKGNAMESUFFIX=	-serverspy
DISTNAME=	mlservspy-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	MLDonkey Server Spy broadcasts your whereabouts on the eDonkey network

RUN_DEPENDS=	\
	${SITE_PERL}/${PERL_ARCH}/Image/Magick.pm:${PORTSDIR}/graphics/ImageMagick \
	${SITE_PERL}/${PERL_ARCH}/auto/TimeDate:${PORTSDIR}/devel/p5-TimeDate \
	${SITE_PERL}/AppConfig.pm:${PORTSDIR}/devel/p5-AppConfig \
	${SITE_PERL}/Net/FTP.pm:${PORTSDIR}/net/p5-Net

USE_PERL5=	yes
USE_SIZE=	yes
NO_BUILD=	yes

BINARY_NAME=	mlservspy.pl
CONFIG_NAME=	mlservspy.ini
IMAGE_NAME=	mlservspy.jpg
DATA_FILES=	mlservspy.ini mlservspy.jpg

post-patch:
# point to correct perl path
	@${PERL} -pi -e \
		's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${BINARY_NAME}
# comment and change default path
# remove needless spaces in line ends
	@${PERL} -pi -e \
		's|^(path).*$$|#\1=~/.mldonkey-serverspy/|; \
		s|[\s\t]+\n$$|\n|' \
		${WRKSRC}/mlservspy.ini

post-configure:
	@${SED} \
		-e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%CONFIG%%|${CONFIG_NAME}|' \
		-e 's|%%IMAGE%%|${IMAGE_NAME}|' \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKSRC}/README.txt \
		${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endif
# install data files (images, sample configuration, etc)
	@${MKDIR} ${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
.for file in ${DATA_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} \
		${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}
.endfor
# install script
	@${INSTALL_SCRIPT} ${WRKSRC}/${BINARY_NAME} \
		${PREFIX}/bin/${BINARY_NAME}-real
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/bin/${BINARY_NAME}

.include <bsd.port.mk>
