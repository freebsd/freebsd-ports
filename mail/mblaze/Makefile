PORTNAME=	mblaze
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1
CATEGORIES=	mail

# mexport: ensure mbox entries are separated by an empty line
PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	7d049328136b466a33279ced6e2de46e4a41a3ef.patch:-p1

MAINTAINER=	loader@FreeBSD.org
COMMENT=	Unix utilities to deal with Maildir

LICENSE=	CC0-1.0 MIT PD
LICENSE_COMB=	multi

USES=		gmake perl5
USE_GITHUB=	yes
USE_PERL5=	test

GH_ACCOUNT=	leahneukirchen
MAKEFILE=	GNUmakefile
TEST_TARGET=	check

.include <bsd.port.mk>
