# New ports collection makefile for:   kannel
# Date created:		19 Jun 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	kannel
PORTVERSION=	1.0.3
CATEGORIES=	www
MASTER_SITES=	http://www.kannel.3glab.org/download/${PORTVERSION}/
DISTNAME=	gateway-${PORTVERSION}

MAINTAINER=	freebsd-ports@freebsd.org

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2

USE_AUTOCONF=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/
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
			do ${ECHO_CMD} share/doc/kannel/$$a >> ${TMPPLIST} ; done
	@${ECHO_CMD} "@dirrm share/doc/kannel/arch" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/kannel/userguide" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm share/doc/kannel" >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
