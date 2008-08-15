# New ports collection makefile for:	p5-Net-Flickr-Backup
# Date created:		2006-08-05
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-Backup
PORTVERSION=	2.991
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	OOP for backing up your Flickr photos locally

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sys/Hostname/FQDN.pm:${PORTSDIR}/sysutils/p5-Sys-Hostname-FQDN \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Text/Unidecode.pm:${PORTSDIR}/converters/p5-Text-Unidecode \
		p5-Image-MetaData-JPEG>=0.15:${PORTSDIR}/graphics/p5-Image-MetaData-JPEG \
		p5-Net-Flickr-RDF>=2.1:${PORTSDIR}/www/p5-Net-Flickr-RDF \
		p5-TimeDate>=1.16:${PORTSDIR}/devel/p5-TimeDate \
		p5-libwww>=5.812:${PORTSDIR}/www/libwww
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	5.8.0+

MAN3=		Net::Flickr::Backup.3

.include <bsd.port.mk>
