PORTNAME=	SAVI-Perl
PORTVERSION=	0.30
PORTREVISION=	6
CATEGORIES=	security perl5
MASTER_SITES=	http://www.csupomona.edu/~henson/archive/projects/SAVI-Perl/dist/
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl5 module interface to Sophos AntiVirus

USES=		perl5
USE_PERL5=	configure
ONLY_FOR_ARCHS=	i386 amd64

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/lib/libsavi.so.3) && !exists(${PREFIX}/lib/libsavi.so)
FAKELIBDIR=${WRKDIR}/lib
CONFIGURE_ARGS+=LDDLFLAGS='-shared -L ${FAKELIBDIR}'
.elif !exists(${PREFIX}/lib/libsavi.so)
IGNORE=		Sophos Anti-Virus needs to be installed (see pkg-descr)
.endif

.if defined(FAKELIBDIR)
pre-configure:
	${MKDIR} ${FAKELIBDIR}
	${LN} -s ${PREFIX}/lib/libsavi.so.3 ${FAKELIBDIR}/libsavi.so
.endif

.include <bsd.port.post.mk>
