from playwright.sync_api import sync_playwright

with sync_playwright() as p:
    #for browser_type in [p.chromium, p.firefox, p.webkit]:
    for browser_type in [p.firefox]:
        browser = browser_type.launch()
        page = browser.new_page()
        page.goto('http://playwright.dev')
        page.screenshot(path=f'example-{browser_type.name}-sync.png')
        browser.close()

