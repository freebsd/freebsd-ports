# New ports collection makefile for:	p5-Net-Amazon-S3
# Date created:		2006-10-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Amazon-S3
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Use the Amazon S3 - Simple Storage Service

RUN_DEPENDS=	p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Digest-HMAC>=0:${PORTSDIR}/security/p5-Digest-HMAC \
		p5-LWP-UserAgent-Determined>=0:${PORTSDIR}/www/p5-LWP-UserAgent-Determined \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	p5-Digest-MD5-File>=0:${PORTSDIR}/security/p5-Digest-MD5-File

PERL_CONFIGURE=	yes

MAN3=		Net::Amazon::S3.3 Net::Amazon::S3::Bucket.3

# remove unused prerequisite
post-patch:
.for f in META.yml Makefile.PL
	@${REINPLACE_CMD} -e '/DateTime::Format::Strptime/d' ${WRKSRC}/${f}
	@${RM} ${WRKSRC}/${f}.bak
.endfor

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
