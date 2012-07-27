# New ports collection makefile for:	p5-vpopmail
# Date created:				12 January 2003.
# Whom:	      				James Raftery <james@now.ie>
#
# $FreeBSD$
#

PORTNAME=	vpopmail
PORTVERSION=	0.08
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SSCANLON
PKGNAMEPREFIX=	p5-

MAINTAINER=	james@now.ie
COMMENT=	Perl module to provide access to vpopmail API

VPOPMAIL_PORT?=	mail/vpopmail

BUILD_DEPENDS=	${LOCALBASE}/vpopmail/lib/libvpopmail.a:${PORTSDIR}/${VPOPMAIL_PORT}
RUN_DEPENDS:=	${BUILD_DEPENDS}

BROKEN=		Does not build

PERL_CONFIGURE=	yes

MAN3=		vpopmail.3

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

.include <bsd.port.post.mk>
