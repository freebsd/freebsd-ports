# $FreeBSD$

PORTNAME=	dtcp
PORTVERSION=	20130602
#PORTREVISION=	0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.mahoroba.org/~ume/ipv6/ \
		http://home.jp.FreeBSD.org/~ume/ipv6/

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Dynamic Tunnel Configuration Protocol daemon and client

.if defined(WITH_QPOPAUTH)
RUN_DEPENDS=	qpopauth:${PORTSDIR}/mail/qpopper
.endif

USE_RC_SUBR=	dtcpc dtcps
USE_RUBY=	yes
MAKE_ENV+=	RUBY=${RUBY}

MAN8=		dtcpauth.8 dtcpc.8 dtcps.8
MANCOMPRESSED=	yes

SUB_LIST+=	RUBY=${RUBY}

PLIST_FILES=	sbin/dtcpauth sbin/dtcpc sbin/dtcps

NO_STAGE=	yes
pre-install:
	@for script in ${USE_RC_SUBR}; do \
		if [ -f ${PREFIX}/etc/rc.d/$${script} ]; then \
			${ECHO_MSG} "Remove old ${PREFIX}/etc/rc.d/$${script} before install."; \
			exit 1; \
		fi; \
	done

.include <bsd.port.mk>
