# Common stuff for Licq-based ports
# $FreeBSD$

PKGNAMEPREFIX=		licq-
TIMESTAMP=		20020128
LICQ_VER=		1.1.0-${TIMESTAMP}
QT_LICQ_VER=		${LICQ_VER}
RMS_LICQ_VER=		0.23
CONSOLE_LICQ_VER=	${LICQ_VER}
AUTO_REPLY_LICQ_VER=	1.0.2
FORWARDER_LICQ_VER=	1.0.1
.if ${PORTNAME} != "base"
RUN_DEPENDS+=		licq:${PORTSDIR}/net/licq
.endif
MASTER_SITES=		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fjoe
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE} \
#			ftp://ftp.wibble.net/pub/licq/srcs/ \
#			ftp://licq.darkorb.net/srcs/ \
#			ftp://ftp.fanfic.org/pub/licq/srcs/ \
#			ftp://ftp.inter-i.uni-mainz.de/pub/licq/srcs/
#MASTER_SITE_SUBDIR=	licq
DISTNAME=		${PKGNAMEPREFIX}daily-${TIMESTAMP}
DISTFILES=		${DISTNAME}.tar.bz2
GNU_CONFIGURE=		yes
MD5_FILE=		${PORTSDIR}/net/licq-devel/distinfo
# USE_LIBTOOL doesn't work for these ports
#USE_LIBTOOL=		yes
USE_GMAKE=		yes
USE_NEWGCC=		yes
USE_BZIP2=		yes

.if defined(USE_CVS)
WRKSRC?=		${WRKDIR}/licq-plugins/${PORTNAME}
DISTFILES=
CVS_MODULE?=		licq-plugins
IS_INTERACTIVE=		yes

do-fetch:

do-extract:
	${MKDIR} ${WRKDIR}
	cvs -d :pserver:anonymous@cvs.licq.sourceforge.net:/cvsroot/licq login
	(cd ${WRKDIR} && cvs -z9 -d :pserver:anonymous@cvs.licq.sourceforge.net:/cvsroot/licq co ${CVS_MODULE})

pre-patch:
	(cd ${WRKSRC} && ${GMAKE} -f Makefile.cvs)
.else
WRKSRC?=		${WRKDIR}/licq-${TIMESTAMP}/plugins/${PORTNAME}
.endif
