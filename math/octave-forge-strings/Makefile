PORTNAME=	octave-forge-strings
DISTVERSIONPREFIX=	release-
DISTVERSION=	1.3.2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3+ BSD2CLAUSE
LICENSE_COMB=	multi

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2

USES=		octave pkgconfig autoreconf
USE_GITHUB=	yes
GH_ACCOUNT= 	gnu-octave
GH_PROJECT=	octave-strings

OCTAVE_SRC=	${GH_PROJECT}-release-${DISTVERSION}

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
