import os
import sys
from pathlib import Path

# Inject these WebKit workaround flags before Tauri initializes
os.environ["WEBKIT_DISABLE_DMABUF_RENDERER"] = "1"
os.environ["WEBKIT_DISABLE_COMPOSITING_MODE"] = "1"

from pytauri import WebviewUrl
from pytauri.webview import WebviewWindowBuilder
from pytauri_wheel.lib import builder_factory, context_factory

def on_setup(app):
    print("Tauri App has been successfully initialized!")

    WebviewWindowBuilder.from_config(
        app,
        {
            "label": "main",
            "url": "https://google.com",  # <-- Pass as a regular string
            "title": "My Complete PyTauri App",
            "width": 1024,
            "height": 768,
            "resizable": True
        }
    )


def main():
    # Identify our mock directory context
    #mock_dir = Path("/tmp/mock_tauri")
    mock_dir = Path(os.environ['MOCK_TAURI_DIR'])
    
    # Generate context via positional-only argument lookup
    context = context_factory(mock_dir)
    
    # 3. Build the application instance with mandatory arguments
    app = builder_factory().build(
        context=context,
        invoke_handler=None,  # No background IPC commands registered yet
        setup=on_setup        # Register our window creation callback hook
    )
    
    # 4. Kick off the blocking application run cycle
    sys.exit(app.run_return())

if __name__ == "__main__":
    main()

