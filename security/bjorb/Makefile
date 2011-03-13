# New ports collection makefile for:	bjorb
# Date created:		May 16, 1998
# Whom:			issei@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	bjorb
PORTVERSION=	0.5.5p1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://people.FreeBSD.org/~foxfair/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Secure TCP relay software with SSL

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_OPENSSL=	YES
USE_PERL5=	yes

.if !defined(BATCH)
INSTALL_TARGET=		install certificate
.endif

USE_AUTOTOOLS=	autoconf213
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

post-install:
	@${INSTALL_SCRIPT} ${DOCSRC}/doc/sample/bjorb.sh ${PREFIX}/etc/rc.d/bjorb.sh.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${DOCSRC}/$i ${DOCSDIR}
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${PREFIX}/share/examples/bjorb
.for i in ${EXAMPLES}
	@${INSTALL_DATA} ${DOCSRC}/$i ${PREFIX}/share/examples/bjorb
.endfor
.endif

.include <bsd.port.mk>
