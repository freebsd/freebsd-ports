# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

CATEGORIES=	www perl5 devel

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache2 Request Library with perl binding

MASTERDIR=	${.CURDIR}/../libapreq2

WITH_MODPERL2=	yes
MAKE_ENV+=	MAKE=${MAKE_CMD} ## MakeMaker blows it without this

.include "${MASTERDIR}/Makefile"
