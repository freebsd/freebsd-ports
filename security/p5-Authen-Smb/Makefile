# Created by: Mustafa Arif <ma499@doc.ic.ac.uk>
# $FreeBSD$

PORTNAME=	Authen-Smb
PORTVERSION=	0.91
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ma499@doc.ic.ac.uk
COMMENT=	Perl extension to authenticate against an SMB server

USES=		perl5
USE_PERL5=	configure

MAN3=	Authen::Smb.3

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/smbval/rfcnb-util.c \
		${WRKSRC}/smbval/session.c \
		${WRKSRC}/smbval/smblib-util.c \
		${WRKSRC}/smbval/smblib.c

.include <bsd.port.mk>
