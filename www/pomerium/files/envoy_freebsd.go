//go:build freebsd

package envoy

import (
	"context"
	"syscall"

	"github.com/pomerium/pomerium/internal/log"
)

var sysProcAttr = &syscall.SysProcAttr{
	Setpgid: true,
}

func (srv *Server) runProcessCollector(_ context.Context) {}

func (srv *Server) prepareRunEnvoyCommand(ctx context.Context, sharedArgs []string) (exePath string, args []string) {
	if srv.cmd != nil && srv.cmd.Process != nil {
		log.Ctx(ctx).Info().Msg("envoy: terminating previous envoy process")
		_ = srv.cmd.Process.Kill()
	}

	args = make([]string, len(sharedArgs))
	copy(args, sharedArgs)

	// Hot-restart uses abstract AF_UNIX sockets which are Linux-only.
	// The system envoy binary is built with hot-restart enabled, so we
	// must disable it at runtime to prevent envoy from aborting on startup.
	args = append(args, "--disable-hot-restart")

	return srv.envoyPath, args
}
