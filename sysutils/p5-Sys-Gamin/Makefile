# Created by: Nick Hibma <n_hibma@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Sys-Gamin
PORTVERSION=	0.1
PORTREVISION=	3
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Gamin (File Access Monitor implementation)

USES=		fam perl5
USE_PERL5=	configure

pre-configure:
	# Pass in include in LOCALBASE
	${PERL} -pi -e 'm/LIBS =>/ && print "  INC => \"-I${LOCALBASE}/include\",\n"' ${WRKSRC}/Makefile.PL
	# Rename a tool with a generic name (monitor)
	${PERL} -pi -e 's/qw.monitor./qw(gamin-monitor)/' ${WRKSRC}/Makefile.PL
	${PERL} -pi -e 's/^monitor$$/gamin-monitor/' ${WRKSRC}/MANIFEST
	${MV} ${WRKSRC}/monitor ${WRKSRC}/gamin-monitor

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Sys/Gamin/Gamin.so

.include <bsd.port.mk>
