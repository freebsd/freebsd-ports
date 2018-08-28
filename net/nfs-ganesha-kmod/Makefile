# $FreeBSD$

PORTNAME=	nfs-ganesha-kmod
DISTVERSION=	0.1
CATEGORIES=	net
DISTVERSIONPREFIX=	v

MAINTAINER=	fatih@gandi.net
COMMENT=	Modules to implement required syscalls for userspace fileservers

LICENSE=	BSD3CLAUSE

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	Gandi
GH_PROJECT=	nfs-ganesha-kmod

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
