/*
 * Copyright (c) 1998  Lars Köller
 * All rights reserved.
 *
 * Handel the FreeBSD Versions in a central file!
 *
 * $FreeBSD$
 */

#ifdef HAVE_SYS_PARAM_H
#  include <sys/param.h>
#endif

#if (defined(BSD) && (BSD >= 199506))
#  include <osreldate.h>
#else
#  error You can compile this xperfmon++ V3.0 only on FreeBSD-3.X systems. xperfmon++ V1.31 up to V2.0 runs on FreeBSD 2.[12].X system!
#endif

#if __FreeBSD_version < 300000
#  error You can compile this xperfmon++ V3.0 only on FreeBSD-3.X systems. xperfmon++ V1.31 up to V2.0 runs on FreeBSD 2.[12].X system!
#endif
