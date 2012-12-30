# New ports collection makefile for:	sysutils/p5-Filesys-SmbClient
# Date created:				August 10, 2003
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Filesys-SmbClient
PORTVERSION=	3.2
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Interface for access Samba filesystem with libsmclient.so

LIB_DEPENDS=	smbclient.0:${PORTSDIR}/net/samba-libsmbclient
BUILD_DEPENDS=	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		Filesys::SmbClient.3

post-patch:
	${PERL} -pi -e 's!%%LOCALBASE%%!${LOCALBASE}!g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
