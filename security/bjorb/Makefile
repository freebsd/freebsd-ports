# New ports collection makefile for:	bjorb
# Version required:	0.5.4p4
# Date created:		May 16, 1998
# Whom:			issei@jp.FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1998/09/25 10:20:21 asami Exp $
#

DISTNAME=	bjorb-0.5.4p4
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.hitachi-ms.co.jp/pub/bjorb/

MAINTAINER=	issei@jp.FreeBSD.ORG

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
BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/openssl
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/openssl

RESTRICTED=	"Cryptography"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

HAS_CONFIGURE=	yes
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
