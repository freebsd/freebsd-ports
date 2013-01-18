# New ports collection makefile for:	p5-SAVI-Perl
# Date created:				April 8th 2004
# Whom:	      				Gary Hayers <Gary@Hayers.net>
#
# $FreeBSD$

PORTNAME=	SAVI-Perl
PORTVERSION=	0.30
PORTREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	http://www.csupomona.edu/~henson/www/projects/SAVI-Perl/dist/
MASTER_SITE_SUBDIR=	security
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 module interface to Sophos AntiVirus

MAN3=		SAVI.3

PERL_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/lib/libsavi.so.3) && !exists(${PREFIX}/lib/libsavi.so)
FAKELIBDIR=${WRKDIR}/lib
CONFIGURE_ARGS+=LDDLFLAGS='-shared -L ${FAKELIBDIR}'
.elif !exists(${PREFIX}/lib/libsavi.so)
IGNORE=		please install Sophos Anti-Virus first
.endif

.if defined(FAKELIBDIR)
pre-configure:
	${MKDIR} ${FAKELIBDIR}
	${LN} -s ${PREFIX}/lib/libsavi.so.3 ${FAKELIBDIR}/libsavi.so
.endif

.include <bsd.port.post.mk>
