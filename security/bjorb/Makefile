# New ports collection makefile for:	bjorb
# Date created:		May 16, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	bjorb
PORTVERSION=	0.5.5p1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.hitachi-ms.co.jp/pub/bjorb/

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	YES
USE_PERL5=	yes

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

USE_AUTOCONF=	yes
CFLAGS+=	-I${OPENSSLINC}/openssl
CONFIGURE_ARGS=	--with-ssltop=${OPENSSLBASE} --with-ssllib=${OPENSSLLIB}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500035
BROKEN=		"Does not compile on 5.0"
.endif

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

.include <bsd.port.post.mk>
