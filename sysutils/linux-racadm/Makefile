PORTNAME=	racadm
PORTVERSION=	11.3.0.0
DISTVERSIONSUFFIX=	-795.el9
CATEGORIES=	sysutils linux
MASTER_SITES=	https://linux.dell.com/repo/hardware/DSU_25.08.25/os_dependent/RHEL9_64/racadm/
PKGNAMEPREFIX=	linux-
DISTNAME=	srvadmin-idracadm7-${DISTVERSIONFULL}
DISTFILES=	srvadmin-argtable2-${DISTVERSIONFULL}${EXTRACT_SUFX_amd64} \
		${DISTNAME}${EXTRACT_SUFX_amd64}

MAINTAINER=	freebsd@gushi.org
COMMENT=	Dell remote access controller admin utility
WWW=		https://www.dell.com/support/home/en-us/drivers/driversdetails?driverId=MFV7T

LICENSE=	DELL
LICENSE_NAME=	Dell Proprietary License
LICENSE_TEXT=	This program is NOT in the public domain.\
		Dell allows free downloads and mirroring of the linux RPMs this port is based on,\
		but you should read the full license here:\
		https://www.dell.com/learn/us/en/uscorp1/legal_terms-conditions_dellgrmwebpage/art-software-license-agreements\
		and determine if it is right for you or your organization.
LICENSE_PERMS=	none

ONLY_FOR_ARCHS=	amd64

USES=		linux:rl9

USE_LINUX_RPM=	yes
MANDIRS=	${PREFIX}/usr/share/man
# Cancel out knobs set by USE_LINUX_RPM, we don't want them for this port
DIST_SUBDIR=
SRC_DISTFILES=
PLIST=		${.CURDIR}/pkg-plist

# racadm dynamically tries to load libssl.so from OpenSSL 1.0
# If it fails to do so, it asks user to put a symlink to a working libssl.so
# under its /opt hierarchy. This can be reproduced by running
# /compat/linux/opt/dell/srvadmin/bin/idracadm7 -r localhost -u root -p xxx getsysinfo
# This post-install target provides the relative symlink
post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib64
	${CP} ${LINUXBASE}/lib64/libssl.so.3 ${STAGEDIR}${PREFIX}/lib64/
	${RLN} ${STAGEDIR}${PREFIX}/lib64/libssl.so.3 ${STAGEDIR}${PREFIX}/opt/dell/srvadmin/lib64/openmanage/private/libssl.so
	${RM} ${STAGEDIR}${PREFIX}/lib64/libssl.so.3
	${RMDIR} ${STAGEDIR}${PREFIX}/lib64
	# Reinstall manpages compressed
	${RM} -r ${STAGEDIR}${PREFIX}/opt/dell/srvadmin/share/man
	${RMDIR} ${STAGEDIR}${PREFIX}/opt/dell/srvadmin/share
	${MKDIR} ${STAGEDIR}${PREFIX}/usr/share/man/man3
	${INSTALL_MAN} ${WRKSRC}/opt/dell/srvadmin/share/man/man3/argtable.3 \
		${STAGEDIR}${PREFIX}/usr/share/man/man3/argtable.3
	${INSTALL_MAN} ${WRKSRC}/opt/dell/srvadmin/share/man/man3/argtable2.3 \
		${STAGEDIR}${PREFIX}/usr/share/man/man3/argtable2.3

.include <bsd.port.mk>
