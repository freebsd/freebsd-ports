# New ports collection makefile for:	zephry
# Version required:	2.0.4
# Date created:		1-Aug-1995
# Whom:			pst
#
# $Id: Makefile,v 1.3 1996/11/07 17:49:38 pst Exp $
#

DISTNAME=	zephyr-2.0.4
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/

.if exists(/usr/lib/libkrb.a) && defined(MAKE_EBONES)
CONFIGURE_ARGS="--with-krb4"
.endif

HAS_CONFIGURE=	yes

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d
ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${INSTALL} -c -m 755 -o bin -g bin ${FILESDIR}/zhm.sh ${ZEPHYR_RCDIR}
	${MKDIR} ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL} -c ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done
	${MKDIR} ${ZEPHYR_RCDIR}

.include <bsd.port.mk>
