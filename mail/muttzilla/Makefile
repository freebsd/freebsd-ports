# ex:ts=8
# Ports collection makefile for:  foo
# Date created:			  Mon Feb 03, 1998
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	muttzilla-0.40
CATEGORIES=	mail www
MASTER_SITES=	http://www3.bc.sympatico.ca/brian_winters/mutt/

MAINTAINER=	obrien@FreeBSD.org

pre-configure:
	@${PERL} -pi.orig \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/muttzilla.h
	@${PERL} -pi.orig \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/mzmail.sh
	@${PERL} -pi.orig \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/mzmail.py
	@${PERL} -pi.orig \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/mznews.sh
	@${PERL} -pi.orig \
		-e "s:/etc/muttzilla.conf:${PREFIX}/etc/muttzilla.conf:g"  \
		${WRKSRC}/mznews.py

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/muttzilla
	@${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/muttzilla
.endif

.include <bsd.port.mk>
