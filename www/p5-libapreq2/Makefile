# New ports collection makefile for:	p5-libapreq2
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

CATEGORIES=	www perl5 devel

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache2 Request Library with perl binding

MASTERDIR=	${.CURDIR}/../libapreq2

WITH_MODPERL2=	yes
MAKE_ENV+=	MAKE=${GMAKE} ## MakeMaker blows it without this

.include "${MASTERDIR}/Makefile"
