# New ports collection makefile for:	srp
# Date created:							07/25/2001
# Whom:									nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	srp
PORTVERSION=	1.7.4
CATEGORIES=	security net
MASTER_SITES=	http://www-cs-students.stanford.edu/~tjw/srp/source/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" INSTALL="/usr/bin/install -C"
CONFIGURE_ARGS=	--with-openssl=/usr				\
		--with-zlib					\
		--enable-loginf

PORTDOCS=	Acknowledgements Copyrights LICENSE copyright.c \
		draft-altman-rfc2942bis-00.txt draft-altman-rfc2944bis-01.txt \
		draft-altman-telnet-fwdx-02.txt \
		draft-ietf-tn3270e-telnet-tls-05.txt rfc2941.txt rfc2942.txt \
		rfc2944.txt rfc2945.txt rfc2946.txt rfc2947.txt rfc2948.txt \
		rfc2949.txt rfc2950.txt rfc2952.txt rfc2953.txt srp.ps

.if !defined(NOPORTDOCS)
post-install:
.for f in ${PORTDOCS}
	${MKDIR} ${PREFIX}/share/doc/srp
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${PREFIX}/share/doc/srp/${f}
	@${ECHO_CMD} share/doc/srp/${f} >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} @dirrm share/doc/srp >> ${TMPPLIST}
.endif

.include <bsd.port.mk>
