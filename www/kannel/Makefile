# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	0.10.2
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/${PORTVERSION}/
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	midom@dammit.lt

LIB_DEPENDS=    xml:${PORTSDIR}/textproc/libxml

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=         ${WRKDIR}/gateway-0.10.2/

do-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && make install-docs
.endif
	@cd ${WRKSRC} && make install
	${INSTALL_DATA} ${WRKSRC}/debian/kannel.conf ${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/debian/kannel.wapconf ${PREFIX}/etc/

.if !defined(NOPORTDOCS)
post-install:
	@cd ${WRKSRC}/doc && \
		for a in `/usr/bin/find . -type f | ${SED} -e 's:^\./::g` ; \
			do ${ECHO} share/doc/kannel/$$a >> ${TMPPLIST} ; done
	@${ECHO} "@dirrm share/doc/kannel/arch" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/kannel/userguide" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/kannel" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
