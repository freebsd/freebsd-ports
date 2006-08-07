# New ports collection makefile for:	p5-Net-Flickr-Backup
# Date created:		2006-08-05
# Whom:			Tsung-Han Yeh <snowfly@yuntech.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	Net-Flickr-Backup
PORTVERSION=	2.8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	snowfly@yuntech.edu.tw
COMMENT=	OOP for backing up your Flickr photos locally

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Sys/Hostname/FQDN.pm:${PORTSDIR}/sysutils/p5-Sys-Hostname-FQDN \
		${SITE_PERL}/File/Find/Rule.pm:${PORTSDIR}/devel/p5-File-Find-Rule \
		${SITE_PERL}/Net/Flickr/RDF.pm:${PORTSDIR}/www/p5-Net-Flickr-RDF \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Text/Unidecode.pm:${PORTSDIR}/converters/p5-Text-Unidecode \
		${SITE_PERL}/Image/MetaData/JPEG.pm:${PORTSDIR}/graphics/p5-Image-MetaData-JPEG \
		${SITE_PERL}/IO/AtomicFile.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Net::Flickr::Backup.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires at least Perl 5.6 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/base.pm:${PORTSDIR}/devel/p5-Class-Fields
.endif

.include <bsd.port.post.mk>
