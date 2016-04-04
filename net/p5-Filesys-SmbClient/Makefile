# Created by: Erwin Lansing <erwin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Filesys-SmbClient
PORTVERSION=	3.2
PORTREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Interface for access Samba filesystem with libsmclient.so

LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
BUILD_DEPENDS=	p5-Test-Simple>=0:devel/p5-Test-Simple

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -i '' -e 's!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Filesys/SmbClient/SmbClient.so

.include <bsd.port.mk>
