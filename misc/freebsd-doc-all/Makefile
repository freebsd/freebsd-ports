# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	freebsd-doc-all
PORTVERSION=	47441
PORTEPOCH=	1
PORTREVISION=	1
CATEGORIES=	misc docs
MASTER_SITES=	#empty
DISTFILES=	#empty
EXTRACT_ONLY=	#empty

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Documentation from the FreeBSD Documentation Project

RUN_DEPENDS+=	bn-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-bn		\
		da-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-da		\
		de-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-de		\
		el-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-el		\
		en-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-en		\
		es-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-es		\
		fr-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-fr		\
		hu-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-hu		\
		it-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-it		\
		ja-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-ja		\
		ko-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-ko		\
		mn-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-mn		\
		nl-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-nl		\
		pl-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-pl		\
		pt-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-pt		\
		ru-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-ru		\
		tr-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-tr		\
		zh_cn-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-zh_cn	\
		zh_tw-freebsd-doc>=${PORTVERSION}:${PORTSDIR}/misc/freebsd-doc-zh_tw

NO_BUILD=	yes

do-install:	# empty

.if make(package)
DEPENDS_TARGET="package"
.endif

.include <bsd.port.mk>
