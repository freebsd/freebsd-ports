# New ports collection makefile for:	bjorb
# Version required:	0.5.3p1
# Date created:		May 16, 1998
# Whom:			issei@t-cnet.or.jp
#
# $Id$

DISTNAME=	bjorb-0.5.3p1
PKGNAME=	bjorb-0.5.3.1
CATEGORIES=	net security
MASTER_SITES=	ftp://ftp.hitachi-ms.co.jp/pub/bjorb/

MAINTAINER=	issei@t-cnet.or.jp

BUILD_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay
RUN_DEPENDS=	ssleay:${PORTSDIR}/security/SSLeay

RESTRICTED=	"Cryptography"

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/src
DOCSRC=		${WRKDIR}/${DISTNAME}
DOCS=		COPYRIGHT \
		README \
		COPYRIGHT.jp \
		INSTALL.jp \
		README.jp \
		doc/bjorb.conf.5.jp.txt \
		doc/features.jp
EXAMPLES=	doc/sample/mail-server.conf \
		doc/sample/mail-client.conf \
		doc/sample/telnet-server.conf \
		doc/sample/telnet-client.conf

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
