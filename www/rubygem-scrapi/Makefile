# New ports collection makefile for:	rubygem-scrapi
# Date created:				29 Jan 2007
# Whom:					IWATSUKI Hiroyuki <don@na.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	scrapi
PORTVERSION=	1.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	don@na.rim.or.jp
COMMENT=	A scrAPI toolkit for Ruby

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/tidy-1.1.2.gemspec:${PORTSDIR}/textproc/rubygem-tidy \
		tidy:${PORTSDIR}/www/tidy-lib

USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	${RM} -f ${LOCALBASE}/${GEM_LIB_DIR}/lib/tidy/libtidy.dll
	${RM} -f ${LOCALBASE}/${GEM_LIB_DIR}/lib/tidy/libtidy.so
	${LN} -sf ${LOCALBASE}/lib/libtidy.so ${LOCALBASE}/${GEM_LIB_DIR}/lib/tidy/

.include "${PORTSDIR}/devel/ruby-gems/Makefile.common"
.include <bsd.port.post.mk>
