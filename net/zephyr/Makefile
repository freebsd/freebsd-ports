# New ports collection makefile for:	zephry
# Version required:	2.0.4
# Date created:		1-Aug-1995
# Whom:			pst
#
# $Id: Makefile,v 1.2 1995/11/27 04:06:01 asami Exp $
#

DISTNAME=	zephyr-2.0.4
CATEGORIES+=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/
HAS_CONFIGURE=	yes

.if exists(/usr/lib/libkrb.a) && defined(MAKE_EBONES)
CONFIGURE_ARGS="--with-krb4"
.endif

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d

ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${INSTALL} -c -m 755 -o bin -g bin ${FILESDIR}/zhm.sh ${ZEPHYR_RCDIR}
	-test -d ${ZEPHYR_DOCDIR} || mkdir -p ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL} -c ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done
	-test -d ${ZEPHYR_RCDIR} || mkdir -p ${ZEPHYR_RCDIR}

.include <bsd.port.mk>
