# New ports collection makefile for:	p5-Net-FS-Flickr
# Date created:		2006-07-30
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-FS-Flickr
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	A Perl interface for store and retrieve files on Flickr

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Data/Dumper.pm:${PORTSDIR}/devel/p5-Data-Dumper \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Acme/Steganography/Image/Png.pm:${PORTSDIR}/graphics/p5-Acme-Steganography-Image-Png \
		${SITE_PERL}/Flickr/Upload.pm:${PORTSDIR}/www/p5-Flickr-Upload
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN1=		flickrfs.1
MAN3=		Net::FS::Flickr.3 \
		Net::FS::Flickr::Access.3

.include <bsd.port.mk>
