# New ports collection makefile for:	zephry
# Version required:	2.0.2
# Date created:		1-Aug-1995
# Whom:			pst
#
# $Id$
#

DISTNAME=	zephyr-2.0.2
CATEGORIES+=	networking
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/dist/
HAS_CONFIGURE=	yes

.if exists(/usr/lib/libkrb.a) && defined(MAKE_EBONES)
CONFIGURE_ARGS="--with-krb4"
.endif

ZEPHYR_DOCDIR=	${PREFIX}/etc/zephyr/doc
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	-test -d ${ZEPHYR_DOCDIR} || mkdir ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL} -c ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done

.include <bsd.port.mk>
