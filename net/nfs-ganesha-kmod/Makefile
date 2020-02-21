# $FreeBSD$

PORTNAME=	nfs-ganesha-kmod
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2
CATEGORIES=	net

MAINTAINER=	freebsd@gandi.net
COMMENT=	Modules to implement required syscalls for userspace fileservers

LICENSE=	BSD3CLAUSE

USES=		kmod

USE_GITHUB=	yes
GH_ACCOUNT=	Gandi

GANESHA_MODULE=	getfhat \
		fhreadlink \
		fhlink \
		setthreaduid \
		setthreadgid \
		setthreadgroups

.for f in ${GANESHA_MODULE}
PLIST_FILES+=	${KMODDIR}/${f}.ko
.endfor

do-install:
.for f in ${GANESHA_MODULE}
	${INSTALL_DATA} ${WRKSRC}/${f}/${f}.ko ${STAGEDIR}/${KMODDIR}/
.endfor

.include <bsd.port.mk>
