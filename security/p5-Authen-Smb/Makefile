# New ports collection makefile for:   p5-Authen-Smb
# Date created:                        Fri 03 January 2002
# Whom:                                Mustafa Arif <ma499@doc.ic.ac.uk>
#                                      http://www.doc.ic.ac.uk/~ma499/
#
# $FreeBSD$
#

PORTNAME=	Authen-Smb
PORTVERSION=	0.91
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	ma499@doc.ic.ac.uk
COMMENT=	Perl extension to authenticate against an SMB server

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Authen::Smb.3

post-patch:
	@${REINPLACE_CMD} -e 's,malloc.h,stdlib.h,' \
		${WRKSRC}/smbval/rfcnb-util.c \
		${WRKSRC}/smbval/session.c \
		${WRKSRC}/smbval/smblib-util.c \
		${WRKSRC}/smbval/smblib.c

.include <bsd.port.mk>
