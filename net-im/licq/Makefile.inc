# Common stuff for Licq-based ports
# $FreeBSD$

PKGNAMEPREFIX=		licq-
LICQ_VER=		1.0.3
QT_LICQ_VER=		${LICQ_VER}
RMS_LICQ_VER=		0.22
CONSOLE_LICQ_VER=	1.0.2
AUTO_REPLY_LICQ_VER=	1.0.1
FORWARDER_LICQ_VER=	1.0.1
.if ${PORTNAME} != "base"
RUN_DEPENDS+=		licq:${PORTSDIR}/net/licq
.endif
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
			ftp://ftp.wibble.net/pub/licq/srcs/ \
			ftp://licq.darkorb.net/srcs/ \
			ftp://ftp.fanfic.org/pub/licq/srcs/ \
			ftp://ftp.inter-i.uni-mainz.de/pub/licq/srcs/
MASTER_SITE_SUBDIR=	licq
DISTNAME=		${PKGNAMEPREFIX}${LICQ_VER}
DISTFILES=		${DISTNAME}.tar.gz
GNU_CONFIGURE=		yes
MD5_FILE=		${PORTSDIR}/net/licq/distinfo
# USE_LIBTOOL doesn't work for these ports
#USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_NEWGCC=		yes
WRKSRC?=		${WRKDIR}/${DISTNAME}/plugins/${PORTNAME}-${PORTVERSION}
