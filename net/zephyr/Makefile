# New ports collection makefile for:	zephry
# Date created:		1-Aug-1995
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	zephyr
PORTVERSION=	20000421
CATEGORIES=	net
MASTER_SITES=	ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/ \
		ftp://athena-dist.mit.edu/pub/ATHENA/zephyr/old/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/zephyr

USE_XLIB=	yes
USE_BISON=	yes

GNU_CONFIGURE=	yes
.if exists(/usr/lib/libkrb.a) && defined(MAKE_EBONES)
CONFIGURE_ARGS="--with-krb4"
.endif

MAN1=		zephyr.1 xzwrite.1 zaway.1 zctl.1 zleave.1 zlocate.1 \
		zmailnotify.1 znol.1 zwgc.1 zwrite.1
MAN8=		zpopnotify.8 zshutdown_notify.8 zstat.8 zephyrd.8 zhm.8

ZEPHYR_RCDIR=	${PREFIX}/etc/rc.d
ZEPHYR_DOCDIR=	${PREFIX}/share/doc/zephyr
ZEPHYR_DOCS=	INSTALL NOTES OPERATING README USING

post-install:
	${MKDIR} ${ZEPHYR_RCDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/zhm.sh ${ZEPHYR_RCDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${ZEPHYR_DOCDIR}
	for file in ${ZEPHYR_DOCS} ; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$file ${ZEPHYR_DOCDIR} ; \
	    done
.endif

.include <bsd.port.mk>
