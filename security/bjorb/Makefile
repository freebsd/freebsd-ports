# New ports collection makefile for:	bjorb
# Version required:	0.5.5p1
# Date created:		May 16, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$
#

DISTNAME=	bjorb-0.5.5p1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.hitachi-ms.co.jp/pub/bjorb/

MAINTAINER=	issei@jp.FreeBSD.org

.if defined(USA_RESIDENT) && ${USA_RESIDENT} != YES && ${USA_RESIDENT} != NO
pre-fetch:
	@${ECHO}
	@${ECHO} You must set variable USA_RESIDENT to YES, if you are USA resident
	@${ECHO} or to NO, if you aren\'t USA resident to build this package.
	@${ECHO} You must also have installed RSAREF if you are USA resident.
	@${FALSE}
.elif defined(USA_RESIDENT)
.if ${USA_RESIDENT} == YES
LIB_DEPENDS=		rsaref.2:${PORTSDIR}/security/rsaref
.endif
.endif
BUILD_DEPENDS=	openssl:${PORTSDIR}/security/openssl
LIB_DEPENDS=	crypto.1:${PORTSDIR}/security/openssl \
		ssl.1:${PORTSDIR}/security/openssl
RUN_DEPENDS=	openssl:${PORTSDIR}/security/openssl

RESTRICTED=	"Cryptography"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

HAS_CONFIGURE=	yes
CFLAGS+=	-I${PREFIX}/include/openssl
CONFIGURE_ARGS=	--with-ssltop=${PREFIX}
WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCSRC=		${WRKDIR}/${DISTNAME}
DOCS=		ChangeLog \
		COPYRIGHT \
		INSTALL \
		README \
		ChangeLog.jp \
		COPYRIGHT.jp \
		INSTALL.jp \
		README.jp \
		doc/bjorb.conf.5.jp.txt \
		doc/features.jp
EXAMPLES=	doc/sample/bjorb.conf.doc

post-install:
	@${INSTALL_SCRIPT} ${DOCSRC}/doc/sample/bjorb.sh ${PREFIX}/etc/rc.d/bjorb.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bjorb
.for i in ${DOCS}
	@${INSTALL_DATA} ${DOCSRC}/$i ${PREFIX}/share/doc/bjorb
.endfor
	@${MKDIR} ${PREFIX}/share/examples/bjorb
.for i in ${EXAMPLES}
	@${INSTALL_DATA} ${DOCSRC}/$i ${PREFIX}/share/examples/bjorb
.endfor
.endif

.include <bsd.port.mk>
