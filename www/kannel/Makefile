# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.org/download/${PORTVERSION}/
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	martti.kuparinen@iki.fi

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_AUTOCONF=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/gateway-${PORTVERSION}/
CFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS+=	--with-malloc=native

do-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC} && make install-docs
.endif
	@cd ${WRKSRC} && make install
	${INSTALL_DATA} ${WRKSRC}/gw/wapkannel.conf ${PREFIX}/etc/
	${INSTALL_DATA} ${WRKSRC}/gw/smskannel.conf ${PREFIX}/etc/

.if !defined(NOPORTDOCS)
post-install:
	@cd ${WRKSRC}/doc && \
		for a in `/usr/bin/find . -type f | ${SED} -e 's:^\./::g'` ; \
			do ${ECHO} share/doc/kannel/$$a >> ${TMPPLIST} ; done
	@${ECHO} "@dirrm share/doc/kannel/arch" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/kannel/userguide" >> ${TMPPLIST}
	@${ECHO} "@dirrm share/doc/kannel" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
